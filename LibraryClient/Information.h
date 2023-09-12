#ifndef _INFORMATION_H__
#define _INFORMATION_H__

#include <cstdlib>
#include <cstring>
#include <QDebug>

/**
 * 枚举类型，每一种协议
 */
typedef enum InformationType
{
    LoginRequest = 0,
    LoginRespond,

    RegisterRequest,
    RegisterRespond,

    DeleteUserRequest,
    DeleteUserRespond,

    BorrowRequest,
    BorrowRespond,

    ReturnRequest,
    ReturnRespond,

    ChangeBorrowLineEditRequest,
    ChangeBorrowLineEditRespond,

    ChangeReturnLineEditRequest,
    ChangeReturnLineEditRespond,

    ButtonOkOfBorrowRequest,
    ButtonOkOfBorrowRespond,

    ButtonOkOfReturnRequest,
    ButtonOkOfReturnRespond
}EnumInformationType;

/**
 * @brief The Information struct
 * 靠此结构体在客户端与服务器之间传递信息
 */

struct Information
{
    int InformationLength;
    int InformationType;
    int MessageLength;
    char Username[20];
    char Password[20];
    char BookName[100];
    char ISBN[100];
    char Message[];
};

/**
 * @brief PrepareInformation
 * @param Length
 * @return
 * 计算需要的内存并申请
 */

inline Information* PrepareInformation(int Length)
{
    uint Len = sizeof(Information) + Length;
    Information* NewInformation = (Information*)malloc(Len);
    memset(NewInformation, 0, Len);
    NewInformation->InformationLength = Len;
    NewInformation->MessageLength = Length;
    return NewInformation;
}

#endif // _INFORMATION_H__
