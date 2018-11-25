void answer(int agr_1,int* agr_2,int agr_3)
{
    *agr_2=agr_3+agr_1;
}

PUSH EBP

MOV EBP, ESP

MOV EAX, [EBP+0x10] 3

ADD EAX, [EBP+0x8] 1

MOV ECX, [EBP+0xc] 2

MOV [ECX], EAX

POP EBP

RET