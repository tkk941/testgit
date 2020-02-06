#include<iostream>
#include<cmath>
#include"fwlib32.h"

#pragma comment(lib,"Fwlib32.lib")

#define test_ip "192.168.0.105"

using std::cout;
using std::endl;


int main()
{
    // 获取库句柄 ( Ethernet ) 并进行连接    
    unsigned short a{0};
    int ret = cnc_allclibhndl3(test_ip, 8193, 10, &a);
    if (ret != EW_OK)
    {
       cout << "发生异常，请检查！" << endl;
       return 0;
    }
    ODBAXIS odb{};
    for (short i = 0; i < 3; i++)
    {
        ret = cnc_relative(a, (short)(i + 1), 8, &odb);
        cout << odb.data[0] * pow(10, -3) << endl;
    }

    cout << "read values" << endl;
}