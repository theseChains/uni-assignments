CREATE PROC ProcessOrder @doc xml
AS
DECLARE @hdoc integer
EXEC sp_xml_preparedocument @hdoc OUTPUT, @doc

EXEC sp_xml_removedocument @hdoc;
DROP PROC ProcessOrder;