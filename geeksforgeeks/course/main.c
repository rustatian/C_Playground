{
//Initial Template for C
#include <stdio.h>
//Position this line where user code will be pasted.
int main() {
    //code

    int t;
    scanf("%d" , &t);

    while(t--)
    {
        int x, y;

        scanf("%d %d", &x, &y);
        // char ch[1];
        // scanf("%s", ch);
        do_operation(x, y);

        printf("
               ");


    }
    return 0;
}
}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

//User function Template for C
void do_operation(int x, int y)
{
    // your code here


}

