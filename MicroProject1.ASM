; Ўкл€р ћихаил »горевич
; Ѕѕ»191
; ¬ариант є28
; ”словие: написать программу, наход€щую все пары перпендикул€рных отрезков среди п€ти введЄнных.

format PE console
entry start

include 'win32a.inc'
include 'Find_perpendicular.inc'

;--------------------------------------------------------------------------
section '.data' data readable writable

        messageStartInput0   db 'Program for the search of the perpendicular segments amoung 5 ones. Input coordinates of segments` end points.', 10, 13, 0
        messageStartInput1   db 'Entering coordinates of the ', 0
        messageStartInput2   db ' vector:', 10, 13, 0
        messageX db 'Input the abscissa of 1 point: ', 0
        messageY db 'Input the ordinate of 1 point: ', 0
        messageX1 db 'Input the abscissa of 2 point: ', 0
        messageY1 db 'Input the ordinate of 2 point: ', 0
        perpMes1  db 'A pair consisting of a segment defined by such coordinates of the end points: (', 0
        perpMes2  db ' ; ', 0
        perpMes3  db ') and (', 0
        perpMes4  db '),', 10, 13, 0
        perpMes41 db 'as well as a segment with such coordinates of the end points: (', 0
        perpMes5  db ")", 10, 13, 0
        perpMes6  db "contains perpendicular line segments.", 10, 13, 0
        conclusionMessage1  db 'To sum up, there was/were ', 0
        conclusionMessage2  db ' pair/pairs of perpendicular line segments in total.', 0
        newStr  db '',10, 13, 0
        repEnter db 'The wrong coordinates input. Entered coordinate have to be less than -10^6 and more than 10^6.', 10, 13, 0
        tryAgain db 'Try again: ', 0
        digit db '%d', 0

        c11          dd ?
        c12          dd ?
        c13          dd ?
        c14          dd ?
        c21          dd ?
        c22          dd ?
        c23          dd ?
        c24          dd ?
        c31          dd ?
        c32          dd ?
        c33          dd ?
        c34          dd ?
        c41          dd ?
        c42          dd ?
        c43          dd ?
        c44          dd ?
        c51          dd ?
        c52          dd ?
        c53          dd ?
        c54          dd ?
        tmpStack     dd ?
        iInp         dd 1
        perpNum      dd 0

;--------------------------------------------------------------------------
section '.code' code readable executable
start:
        ReadAllCoord c11, c12, c13, c14, c21, c22, c23, c24, c31, c32, c33, c34, c41, c42, c43, c44, c51, c52, c53, c54            ; —читываем данные
        FindPerpendicular c11, c12, c13, c14, c21, c22, c23, c24, c31, c32, c33, c34, c41, c42, c43, c44, c51, c52, c53, c54       ; »щем перпендикул€ры
        Conclusion perpNum                                                                                                         ; ƒелаем вывод
finish:
        call [getch]
        invoke ExitProcess, 0

;--------------------------------------------------------------------------
                                                 
section '.idata' import data readable
    library kernel, 'kernel32.dll',\
            msvcrt, 'msvcrt.dll',\
            user32,'USER32.DLL'

include 'api\user32.inc'
include 'api\kernel32.inc'
    import kernel,\
           ExitProcess, 'ExitProcess',\
           HeapCreate,'HeapCreate',\
           HeapAlloc,'HeapAlloc'
  include 'api\kernel32.inc'
    import msvcrt,\
           printf, 'printf',\
           scanf, 'scanf',\
           getch, '_getch'