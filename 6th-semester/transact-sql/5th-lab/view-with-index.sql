DROP INDEX [IX_vStateProvinceCountryRegion] ON [Person].[vStateProvinceCountryRegion];

CREATE UNIQUE CLUSTERED INDEX [IX_vStateProvinceCountryRegion] ON
[Person].[vStateProvinceCountryRegion]
(
[StateProvinceID] ASC, [CountryRegionCode] ASC
)