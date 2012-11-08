static int cache_hit(struct cache_c *dmc, struct bio *bio,
                     struct cacheblock *cache)
{
    ...
    /* LRU */
    down(&dmc->lru_mutex);
    list_move_tail(&cache->list, dmc->lru); /* Move recently addressed block
                                             * to the front of the LRU
                                             */
    up(&dmc->lru_mutex);
    ...
}
