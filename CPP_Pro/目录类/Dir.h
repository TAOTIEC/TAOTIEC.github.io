


#ifndef DIR_H
#define DIR_H
#include <sys/types.h>
#include <dirent.h>
#include "Filename_List.h"
#include <string.h>
#include <iostream>
#include <stdio.h>
using namespace std;

class Dir
{
private:
	DIR *mPath;//文件路径,DIR *opendir(const char *name)

public:
	Dir(string path);//打开指定目录
	//~Dir();
	FNlist Entrylist();//读取目录下的 文件名，并插到链表中
};


#endif