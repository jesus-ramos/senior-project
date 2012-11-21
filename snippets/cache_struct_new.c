struct cache_c {
    ...
    struct radix_tree_root *cache; /* Radix tree for cache blocks
                                    * ordered by sector
                                    */
    struct list_head *lru; /* Link cacheblocks together */
    struct semaphore lru_mutex; /* LRU/LFU list lock */
    ...
};
