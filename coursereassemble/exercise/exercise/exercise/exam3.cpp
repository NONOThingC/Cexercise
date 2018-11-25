extern int sum;
void __stdcall answer(int agr_1,int agr_2,int agr_3,int agr_4)
{
    sum=agr_4-(agr_3-agr_1-agr_2);
}
PUSH EBP

MOV EBP, ESP

MOV EAX, [EBP+0x10] 3

SUB EAX, [EBP+0x8] 1

SUB EAX, [EBP+0xc] 2

MOV ECX, [EBP+0x14] 4

SUB ECX, EAX

MOV sum, ECX

POP EBP

RET 0x10