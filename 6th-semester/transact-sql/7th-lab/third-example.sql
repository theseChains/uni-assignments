CREATE PROC HumanResources.AddDepartment
	@Name nvarchar(50), @GroupName nvarchar(50),
	@DeptID smallint OUTPUT
AS
	INSERT INTO HumanResources.Department (Name, GroupName)
	VALUES (@Name, @GroupName)
SET @DeptID = SCOPE_IDENTITY()

DECLARE @dept int
EXEC HumanResources.AddDepartment 'Refunds', '', @dept OUTPUT
SELECT @dept

ALTER PROC HumanResources.AddDepartment
	@Name nvarchar(50), @GroupName nvarchar(50),
	@DeptID smallint OUTPUT
AS
	IF ((@Name = '') OR (@GroupName = ''))
		RETURN -1
	INSERT INTO HumanResources.Department (Name, GroupName)
	VALUES (@Name, @GroupName)
	SET @DeptID = SCOPE_IDENTITY()
	RETURN 0

DECLARE @dept int, @result int
EXEC @result = HumanResources.AddDepartment 'Refunds', '', @dept OUTPUT
IF (@result = 0)
	SELECT @dept
ELSE
	SELECT 'Error during insert'