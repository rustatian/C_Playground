#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/file.h>
#include <sys/signal.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include "ttyrec.h"
#include "io.h"
#include <pty.h>
#include "getopt.h"

#define HAVE_inet_aton
#define HAVE_scsi_h
#define HAVE_kd_h

#define _(FOO) FOO


void done(void);

void fail(void);

void fixtty(void);

void getmaster(void);

void getslave(void);

void doinput(void);

void dooutput(void);

void doshell(const char *);

char *shell;
FILE *fscript;
int master;
int slave;
int child;
int subchild;
char *fname;

struct termios tt;
struct winsize win;
int aflg;
int uflg;

int main(argc, argv) int argc; char *argv[];
{
    extern int optind;
    int ch;
    void finish();
    char *getenv();
    char *command = NULL;


    // getting options
    while ((ch = getopt(argc, argv, "aue:h?")) != EOF)
        switch ((char) ch) {
            case 'a':
                aflg++;
                break;
            case 'u':
                uflg++;
                break;
            case 'e':
                command = strdup(optarg);
                break;
            case 'h':
            case '?':
            default:
                fprintf(stderr, _("usage: ttyrec [-u] [-e command] [-a] [file]\n"));
                exit(1);
        }

    argc -= optind;
    argv += optind;

    // get a using shell by variable name
    // think about setting this by user
    if (argc > 0)
        fname = argv[0];
    else
        fname = "ttyrecord";
    if ((fscript = fopen(fname, aflg ? "a" : "w")) == NULL) {
        perror(fname);
        fail();
    }

    setbuf(fscript, NULL);

    //done
    shell = getenv("SHELL");
    if (shell == NULL)
        shell = "/bin/sh";

    //done
//    getmaster();
    //done
//    fixtty();

    ////
    (void) signal(SIGCHLD, finish);
    child = fork();
    subchild = child = fork();
    if (child < 0) {
        perror("fork");
        fail();
    }
    /////
    if (child == 0) {
        subchild = child = fork();
        if (child < 0) {
            perror("fork");
            fail();
        }
        if (child)
            dooutput();
        else
            doshell(command);
    }

    doinput();

    return 0;
}

void doinput() {
    register int cc;
    char ibuf[BUFSIZ];

    (void) fclose(fscript);
    while ((cc = read(0, ibuf, BUFSIZ)) > 0) {
        (void) write(master, ibuf, cc);
    }

    done();
}

void finish() {
    int status;
    register int pid;
    register int die = 0;

    while ((pid = wait3((int *) &status, WNOHANG, 0)) > 0)
        if (pid == child)
            die = 1;

    if (die)
        done();
}

struct linebuf {
    char str[BUFSIZ + 1]; /* + 1 for an additional NULL character.*/
    int len;
};

void check_line(const char *line) {
    static int uuencode_mode = 0;
    static FILE *uudecode;

    if (uuencode_mode == 1) {
        fprintf(uudecode, "%s", line);
        if (strcmp(line, "end\n") == 0) {
            pclose(uudecode);
            uuencode_mode = 0;
        }
    } else {
        int dummy;
        char dummy2[BUFSIZ];
        if (sscanf(line, "begin %o %s", &dummy, dummy2) == 2) {
            /*
             * uuencode line found!
             */
            uudecode = popen("uudecode", "w");
            fprintf(uudecode, "%s", line);
            uuencode_mode = 1;
        }
    }
}

void check_output(const char *str, int len) {
    static struct linebuf lbuf = {"", 0};
    int i;

    for (i = 0; i < len; i++) {
        if (lbuf.len < BUFSIZ) {
            lbuf.str[lbuf.len] = str[i];
            if (lbuf.str[lbuf.len] == '\r') {
                lbuf.str[lbuf.len] = '\n';
            }
            lbuf.len++;
            if (lbuf.str[lbuf.len - 1] == '\n') {
                if (lbuf.len > 1) { /* skip a blank line. */
                    lbuf.str[lbuf.len] = '\0';
                    check_line(lbuf.str);
                }
                lbuf.len = 0;
            }
        } else {/* buffer overflow */
            lbuf.len = 0;
        }
    }
}

void dooutput() {
    int cc;
    char obuf[BUFSIZ];

    setbuf(stdout, NULL);
    (void) close(0);
    for (;;) {
        Header h;

        cc = read(master, obuf, BUFSIZ);
        if (cc <= 0)
            break;
        if (uflg)
            check_output(obuf, cc);
        h.len = cc;
        gettimeofday(&h.tv, NULL);
        (void) write(1, obuf, cc);
        (void) write_header(fscript, &h);
        (void) fwrite(obuf, 1, cc, fscript);
    }
    done();
}

void doshell(const char *command) {
    /***
    int t;

    t = open(_PATH_TTY, O_RDWR);
    if (t >= 0) {
        (void) ioctl(t, TIOCNOTTY, (char *)0);
        (void) close(t);
    }
    ***/
    getslave();
    (void) close(master);
    (void) fclose(fscript);
    (void) dup2(slave, 0);
    (void) dup2(slave, 1);
    (void) dup2(slave, 2);
    (void) close(slave);

    if (!command) {
        execl(shell, strrchr(shell, '/') + 1, "-i", 0);
    } else {
        execl(shell, strrchr(shell, '/') + 1, "-c", command, 0);
    }
    perror(shell);
    fail();
}

void fixtty() {
    struct termios rtt;
    rtt = tt;
    cfmakeraw(&rtt);
    rtt.c_lflag &= ~ECHO;
    (void) tcsetattr(0, TCSAFLUSH, &rtt);
}

void fail() {
    (void) kill(0, SIGTERM);
    done();
}

void done() {
    if (subchild) {
        (void) fclose(fscript);
        (void) close(master);
    } else {
        (void) tcsetattr(0, TCSAFLUSH, &tt);
    }
    exit(0);
}

// get a pseudoterminal_master
//void getmaster() {
//    (void) tcgetattr(STDIN_FILENO, &tt); // /* Put the state of FD into *TERMIOS_P.  */ struct termios tt;
//    (void) ioctl(STDIN_FILENO, TIOCGWINSZ, (char *)&win);
//    if (openpty(&master, &slave, NULL, &tt, &win) < 0) {
//        fprintf(stderr, _("openpty failed\n"));
//        fail();
//    }
//}

void getslave() {
    (void) setsid();
    (void) ioctl(slave, TIOCSCTTY, 0);
}
