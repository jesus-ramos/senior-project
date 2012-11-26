struct cacheblock {
    spinlock_t lock;            /* Lock to protect operations on the bio list */
    sector_t   block;           /* Sector number of the cached block */
    sector_t   cacheblock;

    unsigned short  state;      /* State of a block */
    struct bio_list bios;       /* List of pending bios */

    unsigned short   disk;      /* Disk identifier for LV of each VM */
    atomic_t         status;
    struct list_head list;
#ifdef CONFIG_LFU
    unsigned int     hits;      /* Keep track of hits on cacheblock for LFU */
#endif                          /* CONFIG_LFU */
};
