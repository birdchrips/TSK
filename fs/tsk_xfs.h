
#define XFS_MAGIC_NUM 0x58465342

typedef struct xfs_inode {
	uint8_t magic[2];
} xfs_indoe;

typedef struct xfs_sb {
	uint8_t magicnum[4];
	uint8_t blocksize[4];
	uint8_t totalblock[8];
	uint8_t realblock[8];
	uint8_t realextnets[8];
	uint8_t uuid[16];
	uint8_t journalstart[8];
	uint8_t rootinode[8];
	uint8_t realextentsbitmapinode[8];
	uint8_t realbitmapsummaryinode[8];
	uint8_t realextentsize[4];
	uint8_t agsize[4];
	uint8_t agnum[4];
	uint8_t realbitmapblocknum[4];
	uint8_t journalnum[4];
	uint8_t version[2];
	uint8_t sectorsize[2];
	uint8_t inodesize[2];
	uint8_t inodedivblock[2];
	char name[12];
	uint8_t blocklogsize;
	uint8_t sectorlogsize;
	uint8_t inodelogsize;
	uint8_t inodedivblocklogsize;
	uint8_t aglogsize;
	uint8_t realextentslog;
	uint8_t flag;
	uint8_t inodepercentage;
	uint8_t allocinodenum[8];
	uint8_t freeinodenum[8];
	uint8_t freeblocknum[8];
	uint8_t freeextentsnum[8];
	uint8_t userquotainode[8];
	uint8_t groupquotainode[8];
	uint8_t quotaflag[2];
	uint8_t miscflag;
	uint8_t reserved;
	uint8_t inodealignment[4];
	uint8_t raidunit[4];
	uint8_t raidstripe[4];
	uint8_t allocgranularitylog;
	uint8_t externaljournalsectorlog;
	uint8_t externaljournalsectorsize[2];
	uint8_t externaljournalunitsize[4];
	uint8_t addtionalflag[4];
	uint8_t repeataddtionalflag[4];
} xfs_sb;

typedef struct XFS_INFO {
	TSK_FS_INFO fs_info;
	xfs_sb *sb;
	tsk_lock_t lock;
	uint16_t inodesize;
} XFS_INFO;
