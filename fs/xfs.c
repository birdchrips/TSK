

#include "tsk_fs_i.h"
#include "tsk_xfs.h"

#define XFS_SUPERBLOCK_OFFSET 0xCF

TSK_FS_INFO *
xfs_open(TSK_IMG_INFO * img_info, TSK_OFF_T offset,
		TSK_FS_TYPE_ENUM ftype)
{
	XFS_INFO * xfs;
	TSK_FS_INFO * fs;
	int len;

	if((xfs = (XFS_INFO*)tsk_fs_malloc(sizeof(*xfs)))==NULL)return NULL;

	fs = &(xfs->fs_info);
	fs -> ftype = TSK_FS_TYPE_XFS;
	fs -> flags = 0;
	fs -> imginfo = img_info;
	fs -> offset = offset;
	fs -> tag = TSK_FS_INFO_TAG;

	len = sizeof(xfs_sb);

	xfs->sb = (xfs_sb *)tsk_malloc(len);

	tsk_fs_read(fs,XFS_SUPERBLOCK_OFFSET,(char*)xfs->sb,len);
	tsk_fs_guessu32(fs, xfs->sb->magicnum, XFS_MAGIC_NUM);

	fs->inum_count = tsk_getu64(fs->endian, xfs->sb->allocinodenum);
	fs->last_inum = fs->inum_count;
	fs->first_inum = 0x1;
	fs->root_inum = tsk_getu64(fs->endian, xfs->sb->rootinode);
	xfs->inodesize = tsk_getu16(fs->endian, xfs->sb->inodesize);

	fs->deb_bsize = img_info->sector_size;
	fs->block_count = tsk_get64(fs->endian, xfs->sb->totalblock);
	fs->first_block = 0;
	fs->last_block_act = fs->last_block = fs->block_count - 1;
	fs->block_size = 0x1 << xfs->sb->blocklogsize;

	if((TSK_DADDR_T) ((img_info->size - offset)/fs->block_size) < fs->block_count) fs->last_block_act = (img_info->size - offset) / fs->block_size - 1;

	for(fs->fs_id_used = 0;fs->fs_id_used <16; fs->fs_id_used++)
		fs->fs_id[fs->fs_id_used] = xfs->sb->uuid[fs->fs_id_used];

	

	printf("hello\n");

	return fs;
}

