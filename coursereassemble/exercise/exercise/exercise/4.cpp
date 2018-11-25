char testfunc(char agr_1,char agr_2,char agr_3);
char answer(char agr_1,char agr_2,char agr_3)
{
    char a;
    a=agr_2-(agr_1-agr_3)+testfunc( agr_2, agr_1, agr_3);
    return a;
}
PUSH EBP
MOV EBP, ESP

PUSH ECX

PUSH EBX

MOVSX EBX, [EBP+0xc] 2

MOVSX EAX, [EBP+0x8] 1

MOVSX ECX, [EBP+0x10] 3

SUB EAX, ECX

SUB EBX, EAX

MOV DL, [EBP+0x10]

PUSH EDX

MOV AL, [EBP+0x8]

PUSH EAX

MOV CL, [EBP+0xc]

PUSH ECX

CALL testfunc

ADD ESP, 0xc

MOVSX EDX, AL

ADD EBX, EDX

MOV [EBP-0x4], BL

MOV AL, [EBP-0x4]

POP EBX

MOV ESP, EBP

POP EBP

RET

