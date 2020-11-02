;--------------------------------------------------------------------------
macro ReadAllCoord c11, c12, c13, c14, c21, c22, c23, c24, c31, c32, c33, c34, c41, c42, c43, c44, c51, c52, c53, c54 {
  cinvoke printf, messageStartInput0
  ReadCoord c11, c12, c13, c14
  ReadCoord c21, c22, c23, c24
  ReadCoord c31, c32, c33, c34
  ReadCoord c41, c42, c43, c44
  ReadCoord c51, c52, c53, c54
}

;--------------------------------------------------------------------------
macro ReadCoord x, y, x1, y1 {
      cinvoke printf, messageStartInput1
      cinvoke printf, digit, dword [iInp]
      cinvoke printf, messageStartInput2
      cinvoke printf, messageX
      RightScan x
      cinvoke printf, messageY
      RightScan y
      cinvoke printf, messageX1
      RightScan x1
      cinvoke printf, messageY1
      RightScan y1
      add [iInp], 1
      cinvoke printf, newStr
}

;--------------------------------------------------------------------------
macro RightScan scanAdres {
      local ..TheBeginning
      ..TheBeginning:
        mov [tmpStack], esp
        cinvoke scanf, digit, scanAdres
        local ..RepeatInput
        cmp [scanAdres], -1000000
        jl ..RepeatInput
        cmp [scanAdres], 1000000
        jg ..RepeatInput
        mov esp, [tmpStack]
        local ..Over
        jmp ..Over
      ..RepeatInput:
        cinvoke printf, newStr
        cinvoke printf, repEnter
        cinvoke printf, tryAgain
        jmp ..TheBeginning
      ..Over:
        ;ret
}
;--------------------------------------------------------------------------
macro FindPerpendicular c11, c12, c13, c14, c21, c22, c23, c24, c31, c32, c33, c34, c41, c42, c43, c44, c51, c52, c53, c54 {
  IsPerpendicular c11, c12, c13, c14, c21, c22, c23, c24
  IsPerpendicular c11, c12, c13, c14, c31, c32, c33, c34
  IsPerpendicular c11, c12, c13, c14, c41, c42, c43, c44
  IsPerpendicular c11, c12, c13, c14, c51, c52, c53, c54
  IsPerpendicular c21, c22, c23, c24, c31, c32, c33, c34
  IsPerpendicular c21, c22, c23, c24, c41, c42, c43, c44
  IsPerpendicular c21, c22, c23, c24, c51, c52, c53, c54
  IsPerpendicular c31, c32, c33, c34, c41, c42, c43, c44
  IsPerpendicular c31, c32, c33, c34, c51, c52, c53, c54
  IsPerpendicular c41, c42, c43, c44, c51, c52, c53, c54
}
;--------------------------------------------------------------------------
macro IsPerpendicular x1, y1, x2, y2, x3, y3, x4, y4 {
      mov [tmpStack], esp

      mov eax, [x2]
      sub eax, [x1]
      mov ebx, [x4]
      sub ebx, [x3]
      mov edx, 0
      imul ebx
      mov ecx, eax

      mov eax, [y2]
      sub eax, [y1]
      mov ebx, [y4]
      sub ebx, [y3]
      mov edx, 0
      imul ebx

      add eax, ecx
      cmp eax, 0
      local ..PerpendicularFound
      je ..PerpendicularFound

      mov esp, [tmpStack]

      local ..Over
      jmp ..Over

..PerpendicularFound:
        cinvoke printf, perpMes1               ; ѕара, состо€ща€ из отрезока с координатами концевых точек: (
        cinvoke printf, digit, dword [x1]
        cinvoke printf, perpMes2               ; ;
        cinvoke printf, digit, dword [y1]
        cinvoke printf, perpMes3               ; ) и (
        cinvoke printf, digit, dword [x2]
        cinvoke printf, perpMes2
        cinvoke printf, digit, dword [y2]
        cinvoke printf, perpMes4               ; ), а также отрезка с координатами концевых точек: (
        cinvoke printf, perpMes41
        cinvoke printf, digit, dword [x3]
        cinvoke printf, perpMes2
        cinvoke printf, digit, dword [y3]
        cinvoke printf, perpMes3
        cinvoke printf, digit, dword [x4]
        cinvoke printf, perpMes2
        cinvoke printf, digit, dword [y4]
        cinvoke printf, perpMes5               ; ")", 10, 13, 0
        cinvoke printf, perpMes6               ; "содержит перпендикул€рные отрезки.", 10, 13, 0
        add [perpNum], 1
..Over:
        ;ret
}

;--------------------------------------------------------------------------
macro Conclusion pNum {
  cinvoke printf, newStr
  cinvoke printf, conclusionMessage1           ; ¬сего нашлось
  cinvoke printf, digit, dword [pNum]
  cinvoke printf, conclusionMessage2           ; пар перпендикул€рных отрезков.
}