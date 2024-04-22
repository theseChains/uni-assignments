EXEC sp_helpindex [Production.Product]
SELECT a.index_id, name, avg_fragmentation_in_percent
FROM sys.dm_db_index_physical_stats (DB_ID(N'AdventureWorks2022'),
    OBJECT_ID(N'Production.Product'), NULL, NULL, NULL) AS a
JOIN sys.indexes AS b ON a.object_id = b.object_id AND a.index_id = b.index_id;

ALTER INDEX AK_Product_Name ON Production.Product
REORGANIZE

ALTER INDEX AK_Product_ProductNumber ON Production.Product
REBUILD
