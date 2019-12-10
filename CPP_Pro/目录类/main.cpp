#include <iostream>
#include "Dir.h"
#include "Filename_List.h"
using namespace std;

int main()
{
	Dir dir("/mnt/hgfs/Workspace");	//可变的 指定路径
	FNlist list = dir.Entrylist();
	list.PrintList();
}



