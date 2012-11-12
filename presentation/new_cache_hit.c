static int cache_hit(struct cache_c *dmc, struct bio *bio,
                     struct cacheblock *cache)
{
    ...
    /* LRU */
    down(&dmc->lru_mutex);
    /* Move recently addressed block to the front of the LRU */
    list_move_tail(&cache->list, dmc->lru);
    up(&dmc->lru_mutex);
    ...
}
