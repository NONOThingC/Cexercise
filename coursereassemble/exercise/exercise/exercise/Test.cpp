int testfunc(int agr_1,int agr_2,int agr_3,int agr_4,int agr_5);
int answer(int agr_1,int agr_2,int agr_3,int agr_4,int agr_5)
{
    int a;
    a=agr_2-agr_3-agr_4+agr_1-agr_5+testfunc(agr_2,agr_3,agr_4,agr_1,agr_5);
    return a;
}