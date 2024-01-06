#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "addressBook.h"

#define DEEPCOLOUR           0    //通讯录不为空，2、3、4选项颜色与其他颜色相同
#define LIGHTCOLOUR          2    //通讯录为空，2、3、4选项颜色变浅

#define FIRST                0    //第一次进入通讯录菜单
#define NOFIRST              1    //第二次进入通讯录菜单

#define ADDCONTACTS         '1'    //新增联系人
#define SEARCHCONTACTS      '2'    //查找联系人
#define DELECONTACTS        '3'    //删除联系人
#define CHANGECONTACTS      '4'    //修改联系人
#define EXITPROCEDURE       '5'    //退出程序

int nums = 0;

/* 初次进入通讯录标记 */
int enter = FIRST; 

/* 联系人排序方式 */
int compare()
{
    
    return 0;
}

/* 联系人信息打印函数*/
int contactsPrint()
{

    return 0;
}

//处理输入缓存区的垃圾字符，防止用户输入非法值
void clearBuffer()      
{
    char ch = 0;
    while (ch = getchar() != '\n' && ch != EOF);   
}

//打印一行-
int print_()    
{
    printf("\033[0;30;47m\t--------------------\n");
    return 0;
}

//打印一行空格
int printspace(int line)    
{
    for (int idx = 0; idx < line; idx++)
    {
        printf("\033[0;30;47m\t|                  |\n");
    }
    return 0;
}

/* 新增联系人成功界面 */
void newSuccessfullyAdded()
{
    system("clear");//清屏
    print_();
    printspace(4);
    printf("\033[0;30;47m\t|  新增联系人成功  |\n");
    printspace(4);
    print_();
    printf("\033[0;0;0m\n");
    sleep(1.75);
    funcManu(); 
}

/* 查找联系人成功界面 */
void searchSuccessful()
{
    system("clear");//清屏
    print_();
    printspace(4);
    printf("\033[0;30;47m\t|  查找联系人成功  |\n");
    printspace(4);
    print_();
    printf("\033[0;0;0m\n");
    sleep(1.75);
    funcManu(); 
}

/* 联系人不存在提示界面 */
void searchFaild()
{
    system("clear");//清屏
    print_();
    printspace(4);
    printf("\033[0;30;47m\t|  联系人不存在    |\n");
    printspace(4);
    print_();
    printf("\033[0;0;0m\n");
    sleep(1.75);
    funcManu(); 
}

/* 删除联系人成功界面 */
void deleteSuccessful()
{
    system("clear");//清屏
    print_();
    printspace(4);
    printf("\033[0;30;47m\t|  删除联系人成功  |\n");
    printspace(4);
    print_();
    printf("\033[0;0;0m\n");
    sleep(1.75);
    funcManu(); 
}

/* 修改联系人成功界面 */
void modifiedSuccessfully()
{
    system("clear");//清屏
    print_();
    printspace(4);
    printf("\033[0;30;47m\t|  修改联系人成功  |\n");
    printspace(4);
    print_();
    printf("\033[0;0;0m\n");
    sleep(1.75);
    funcManu(); 
}

/* 联系人列表为空提示界面 */
void IsEmptyAddressBook()
{
    system("clear");//清屏
    print_();
    printspace(4);
    printf("\033[0;30;47m\t|  联系人列表为空  |\n");
    printspace(4);
    print_();
    printf("\033[0;0;0m\n");
    sleep(1.75);
    funcManu(); 
}

/* 是否退出？ */
int ConfirmExit()
{
    system("clear");//清屏
    print_();
    printspace(4);
    printf("\033[0;30;47m\t|  确认退出通讯录? |\n");
    printspace(4);
    print_();
    printf("\033[0;0;0m\n");

    printf("输入(1退出,其余输入返回菜单):\t");

    return 0;
}

/* 退出通讯录成功界面 */
int exitSuccessful()
{
    system("clear");//清屏
    print_();
    printspace(4);
    printf("\033[0;30;47m\t|  退出通讯录成功  |\n");
    printspace(4);
    print_();
    printf("\033[0;0;0m\n");
    exit(0);
    return 0;
}

void PowerOnAnimation()   //开机动画
{
    
    system("clear");//清屏

    print_();//打印顶层边框
    printspace(2);
    printf("\033[0;30;47m\t|  欢迎使用通讯录  |\n");
    printspace(2);
    printf("\033[0;30;47m\t|   加载中 。      |\n");
    printspace(3);
    print_();
    printf("\033[0;0;0m\n");
    sleep(1.5);
    system("clear");

    print_();
    printspace(2);
    printf("\033[0;30;47m\t|  欢迎使用通讯录  |\n");
    printspace(2);
    printf("\033[0;30;47m\t|   加载中 。。    |\n");
    printspace(3);
    print_();
    printf("\033[0;0;0m\n");
    sleep(1.5);
    system("clear");

    print_();
    printspace(2);
    printf("\033[0;30;47m\t|  欢迎使用通讯录  |\n");
    printspace(2);
    printf("\033[0;30;47m\t|   加载中 。。。  |\n");
    printspace(3);
    print_();
    printf("\t\033[0;0;0m\n");
    sleep(1.5);
}

/* 选项字体类型选择 */
int numsIsEmpty(int nums)
{
    return nums == 0 ? LIGHTCOLOUR : DEEPCOLOUR;
}

//当输入了非选项值时的提示信息显示
int illegalInputDisplay()   
{
    system("clear");
    print_();
    printspace(2);
    printf("\033[0;30;47m\t|    输入错误！    |\n");
    printspace(2);
    printf("\033[0;30;47m\t| 请输入正确的编号 |\n");
    printspace(3);
    print_();
    sleep(1.7);
}

int choiseFunc()    //选择功能
{
    char choise = 0;
    int ch = 0;

    while (1)
    {
        scanf("%c", &choise);/* 读取缓存区一个字符到choice中 */
        while ((ch = getchar()) != '\n');/* 当输入一串字符串时，清空缓存区多余字符 */

        if (choise < '1' || choise > '5')
        {
            illegalInputDisplay();
            printf("\t\033[0;0;0m\n");
            funcManu();
            continue;
        }
        else
        {
            break;
        }
    }
    switch (choise)
    {   
        case ADDCONTACTS:/* 新增联系人 */
        {
            newSuccessfullyAdded();
            break;
        }

        case SEARCHCONTACTS:/* 查找联系人 */
        {
            if(nums == 0)
            {
                /* 提示通讯录为为空 */
                IsEmptyAddressBook();
            }
            else
            {
                /* 查找联系人成功界面 */
                searchSuccessful();
            }
            
            break;
        }
            
         
        case DELECONTACTS:/* 删除联系人 */   
        {
            if(nums == 0)
            {
                /* 提示通讯录为为空 */
                IsEmptyAddressBook();
            }
            else
            {
                /* 删除联系人成功界面 */
                deleteSuccessful();
            }
            
            break;
        }
            
        
        case CHANGECONTACTS:/* 修改联系人*/
        {
            if(nums == 0)
            {
                /* 提示通讯录为为空 */
                IsEmptyAddressBook();
            }
            else
            {
                /* 修改联系人成功界面 */
                modifiedSuccessfully();
            }
            
            break;
        }
            
        case EXITPROCEDURE:/* 退出程序 */
        {
            ConfirmExit();
            char determine = 0;
            scanf("%c", &determine);
            if(determine == '1')
            {
                /* 退出通讯录 */
                exitSuccessful();
            }
            else
            {
                /* 清空缓存区，防止返回菜单时自动读取缓存区中的换行符（Enter） */
                while ((determine = getchar()) != '\n');
                funcManu(); 
            }
            
            break;
        }
    }
}

int funcManu()      //功能菜单入口函数
{
    if (enter == FIRST)
    {
        enter = NOFIRST;    //修改enter标记为非第一次进入
        PowerOnAnimation();     //开机动画
    }

    system("clear");
    print_();
    printspace(1);
    printf("\033[0;30;47m\t|  请输入功能选项  |\n");
    printspace(1);
    printf("\033[0;30;47m\t|   1.新增联系人   |\n");
    /* |边框和文字分开配置，不一起变色 */
    printf("\t|\033[%d;30;47m   2.查找联系人   \033[0;30;47m|\n", numsIsEmpty(nums));
    printf("\t|\033[%d;30;47m   3.删除联系人   \033[0;30;47m|\n", numsIsEmpty(nums));
    printf("\t|\033[%d;30;47m   4.修改联系人   \033[0;30;47m|\n", numsIsEmpty(nums));
    printf("\033[0;30;47m\t|   5.退出通讯录   |\n");
    printspace(1);
    print_();
    printf("\t\033[0;0;0m\n");//重置文本属性为默认属性
    printf("输入:\t");

    /* 进入功能菜单后调用功能选择函数 */
    choiseFunc();

    return 0;
}


