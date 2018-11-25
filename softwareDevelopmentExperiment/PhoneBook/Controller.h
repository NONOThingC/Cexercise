class Controller
{
public:
    Controller():funCode(-1){}//funCode是功能码，1为增加号码，2为删除号码，3为查询号码,0为退出输入其他无效，直接滞留主界面
    ~Controller();
    void Start();//start用来初始化和调用非控制类的代码
protected:
    int funCode;
};
