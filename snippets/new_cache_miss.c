static int cache_read_miss(struct cache_c *dmc, struct bio *bio, int disk)
{
    ...
    struct cacheblock *cache;
    /* Read new block, insert it add the head of the LRU */
    /* Same in cache_write_miss */
    down(&dmc->lru_mutex);
    cache = list_first_entry(dmc->lru, struct cacheblock, list);
    list_move_tail(&cache->list, dmc->lru);
    up(&dmc->lru);
    ...
}
