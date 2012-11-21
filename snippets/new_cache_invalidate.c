/* Invalidate block from the end of the LRU, passed as cache parameter */
static void cache_invalidate(struct cache_c *dmc, struct cacheblock *cache)
{
    spin_lock(&cache->lock);
    clear_state(cache->state, VALID);
    radix_tree_delete(dmc->cache, get_block_index(cache->block,cache->disk));
    list_del(&cache->list);
    spin_unlock(&cache->lock);
}
