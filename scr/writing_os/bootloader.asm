;e9 fd ff 00 00 00 00 00 00 00 00 00 00 00 00 00
;00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00
;[ 29 more lines with sixteen zero-bytes each ]
;00 00 00 00 00 00 00 00 00 00 00 00 00 00 55 aa
; https://www.felixcloutier.com/x86/jmp

loop:
    jmp loop

times 510-($-$$) db 0

dw 0xaa55