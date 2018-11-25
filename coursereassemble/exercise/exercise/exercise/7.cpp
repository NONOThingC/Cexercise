extern char sum;
void __stdcall answer(char agr_1,char agr_2,char agr_3,char agr_4)
{
    agr_1=agr_1-agr_3;
    agr_1=agr_1-agr_4;
    agr_2=agr_2-agr_1;
    sum=agr_2;
    return;
}
PUSH EBP
MOV EBP, ESP
MOVSX EAX, [EBP+0xc] 2
MOVSX ECX, [EBP+0x8] 1
MOVSX EDX, [EBP+0x10] 3
SUB ECX, EDX 1=1-3
MOVSX EDX, [EBP+0x14] 4
SUB ECX, EDX 1=1-4
SUB EAX, ECX 2=2-1
MOV sum, AL
POP EBP
RET 0x10