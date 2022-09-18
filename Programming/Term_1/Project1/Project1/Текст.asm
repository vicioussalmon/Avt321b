.586 
.model flat
.data
A1 dw 9
.code
ExitProcess PROTO STDCALL :DWORD
_start:

mov A1,6 


Invoke ExitProcess, 0  
end_start
