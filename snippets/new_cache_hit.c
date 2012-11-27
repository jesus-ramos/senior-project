static int cache_hit(struct cache_c *dmc, struct bio *bio,
                     struct cacheblock *cache)
{
    ...
    /* LRU */
    down(&dmc->lru_mutex);
    /* Move recently addressed block to the front of the LRU */
    list_move_tail(&cache->list, dmc->lru);
    up(&dmc->lru_mutex);

#ifdef CONFIG_LFU
    struct cacheblock *next_block;

    down(&dmc->lru_mutex);
    cache->hits++;
    if (unlikely(list_single(dmc->lru)))
        goto no_cmp;
    next_block = list_entry(cache->list.prev, struct cacheblock);
    if (cache->hits >= next_block->hits)
        list_swap(&cache->list, &next_block->list);
no_cmp:
    up(&dmc->lru_mutex);
#endif /* CONFIG_LFU */
    ...
}
