int testfunc(int agr_1,int agr_2,int agr_3);
int answer(int agr_1,int agr_2,int agr_3)
{
    int a;
    a=agr_2-(agr_1-agr_3)+testfunc( agr_2, agr_1, agr_3);
    return a;
}

PUSH EBP
MOV EBP, ESP

PUSH ECX

PUSH ESI

MOV ESI, [EBP+0xc]  ESI=2-3-4+1-5

SUB ESI, [EBP+0x10] 

SUB ESI, [EBP+0x14] 

ADD ESI, [EBP+0x8] 

SUB ESI, [EBP+0x18] 5

MOV EAX, [EBP+0x18]

PUSH EAX

MOV ECX, [EBP+0x8]

PUSH ECX

MOV EDX, [EBP+0x14]

PUSH EDX

MOV EAX, [EBP+0x10]

PUSH EAX

MOV ECX, [EBP+0xc]

PUSH ECX

CALL testfunc

ADD ESP, 0x14

ADD ESI, EAX

MOV [EBP-0x4], ESI

MOV EAX, [EBP-0x4]

POP ESI

MOV ESP, EBP

POP EBP

RET