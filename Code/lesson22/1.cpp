#include <Windows.h>
#include <stdio.h>

int main()
{
    //获取卷
    DWORD gLd = GetLogicalDrives();
    printf("GetLogicalDrives: %x\n", gLd);
    //获取所有逻辑驱动器的字符串
    DWORD len = 100;
    char szbuffer[100];

    GetLogicalDriveStrings(len, (LPWSTR)szbuffer);

    //  获取卷（逻辑驱动器）的类型
    UINT type = GetDriveType(TEXT("D:\\"));

    if (type == DRIVE_UNKNOWN)
    {
        printf("无法确定驱动器的类型 \n");
    }
    else if (type == DRIVE_NO_ROOT_DIR)
    {
        printf("根路径是无效的，例如: 在该路径上没有安装任何卷 \n");
    }
    else if (type == DRIVE_REMOVABLE)
    {
        printf("磁盘可以从驱动器中取出 \n");
    }
    else if (type == DRIVE_FIXED)
    {
        printf("驱动器有固定介质；例如，硬盘驱动器或闪存驱动器。 \n");
    }
    else if (type == DRIVE_REMOTE)
    {
        printf("该驱动器是一个远程（网络）驱动器 \n");
    }
    else if (type == DRIVE_CDROM)
    {
        printf("该驱动器是一个CD-ROM驱动器 \n");
    }
    else if (type == DRIVE_RAMDISK)
    {
        printf("该驱动器是一个RAM磁盘 \n");
    }

    // 获取卷的信息
    TCHAR szVolumeName[260];
    DWORD dwVolumeSerialNumber;
    DWORD dwMaximumComponentLength;
    DWORD dwFileSystemFlags;
    TCHAR szFileSystemNameBuffer[260];
    GetVolumeInformation(
        TEXT("C:\\"),
        szVolumeName,              //输出类型，返回卷名
        260,                       //输入类型，卷名长度
        &dwVolumeSerialNumber,     //输出类型，卷宗序列号
        &dwMaximumComponentLength, //输出类型，指定文件系统支持的文件名组件的最大长度
        &dwFileSystemFlags,        //输出类型，与指定文件系统相关的标志
        szFileSystemNameBuffer,    //输出类型，文件系统（如FAT或NTFS）名称
        260);                      //输入类型，文件系统名称的长度

    return 0;
}