CREATE XML INDEX XMLPATH_ProductModel_CatalogDescription
ON Production.ProductModel(CatalogDescription)
USING XML INDEX PXML_ProductModel_CatalogDescription
FOR PATH

CREATE XML INDEX XMLPROPERTY_ProductModel_CatalogDescription
ON Production.ProductModel(CatalogDescription)
USING XML INDEX PXML_ProductModel_CatalogDescription
FOR PROPERTY

CREATE XML INDEX XMLVALUE_ProductModel_CatalogDescription
ON Production.ProductModel(CatalogDescription)
USING XML INDEX PXML_ProductModel_CatalogDescription
FOR VALUE

EXEC sp_helpindex 'Production.ProductModel';

SELECT 
    i.name AS IndexName,
    i.type_desc AS IndexType,
    i.is_primary_key AS IsPrimaryKey,
    i.is_unique AS IsUnique,
    i.is_unique_constraint AS IsUniqueConstraint,
    c.name AS ColumnName
FROM sys.indexes AS i
INNER JOIN sys.index_columns AS ic ON i.object_id = ic.object_id AND i.index_id = ic.index_id
INNER JOIN sys.columns AS c ON ic.object_id = c.object_id AND ic.column_id = c.column_id
WHERE i.object_id = OBJECT_ID('Production.ProductModel') AND i.type_desc = 'XML'
ORDER BY i.name, ic.key_ordinal;
