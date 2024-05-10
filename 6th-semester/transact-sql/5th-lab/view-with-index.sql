DROP INDEX [IX_vStateProvinceCountryRegion] ON [Person].[vStateProvinceCountryRegion];

CREATE UNIQUE CLUSTERED INDEX [IX_vStateProvinceCountryRegion] ON
[Person].[vStateProvinceCountryRegion]
(
[StateProvinceID] ASC, [CountryRegionCode] ASC
)SELECT StateProvinceID, CountryRegionCodeFROM Person.vStateProvinceCountryRegionWHERE CountryRegionCode IN ('AU', 'FR', 'US');EXEC sp_helpindex [Person.vStateProvinceCountryRegion];