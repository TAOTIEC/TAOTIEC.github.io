#include "Dir.h"
#include "sys/types.h"
#include "dirent.h"

Dir::Dir(string path)//打开指定目录
{
	mPath = opendir(path.c_str());

	if(mPath == nullptr)
	{
		throw "path is inexist!!!\n";
	}
}


FNlist Dir::Entrylist()
{
	//Dir dir("/mnt/hgfs/Workspace");
	FNlist list;
	struct dirent *pent;//struct dirent *readdir(DIR *dir)
	while( (pent = readdir(mPath)) != nullptr )
	{
		list.Insert(pent->d_name);
	}
	//list.PrintList();
	return list;
}

