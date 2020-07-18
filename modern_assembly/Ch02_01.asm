; extern "C" int IntegerAddSub_(int a, int b, int c, int d);

global integeraddsub
section .text

; Calculate a+b+c-d
integeraddsub:
    mov eax, edi ;eax = a
    add eax, esi ;eax = a+b
    add eax, edx ;eax=a+b+c
    sub eax, ecx ;eax=a+b+c-d
    ret
