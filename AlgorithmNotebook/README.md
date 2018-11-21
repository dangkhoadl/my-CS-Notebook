
## Data type Ranges

| TypeName        | Bytes           | Other Names  | Range | Range E |
|:-------------:|:-------------:|:--------:|:-------------:|:--------:|
| bool        | 1 |  | __false__ or __true__ |  |
| char        | 1 | __int8, signed char  | __-128__ to __127__ |  __-1.28E+02__ to __1.27E+02__|
|   unsigned char        | 1 | unsigned __int8 | __0__ to __255__ | __0__ to __2.55E+02__ |
|       short        | 2 | __int16, short int, signed short int | __–32,768__ to __32,767__ | __-3.27E+04__ to __3.27E+04__ |
|       unsigned short        | 2 | unsigned __int16, unsigned short int |  __0__ to __65,535__ | __0__ to __6.55E+04__ |
| int        | 4 | __int32, signed, signed int, long int, signed long int  | __-2,147,483,648__  to  __2,147,483,647__ | __-2.14E+09 to 2.14E+09__ |
| unsigned        | 4 | unsigned __int32, unsigned int, unsigned long int, unsigned long | __0__ to __4,294,967,295__ | __0__ to __4.29E+09__ |
|       long long        | 8 | __int64, signed long long |  __–9,223,372,036,854,775,808__ to __9,223,372,036,854,775,807__ | __-9.22E+18__ to __9.22E+18__ |
|       unsigned long long        | 8 | unsigned __int64 |  __0__ to __18,446,744,073,709,551,615__ | __0__ to __1.84E+19__ |
|       float        | 4 |  |   | Min: __1.17E-38__ - Max: __3.4E+38__ |
|       double        | 8 | long double |   | Min: __2.22E-308__ - Max: __1.79E+308__ |


## Consider Sorting - Grouping duplicated elements as always 
Consider grouping duplicates to reduce runtime of map, priorityqueue etc...

    2 2 2 3 5
    -> [{2:3}, {3:1}, {5:1}]
    
- map<int, int>
- map<int, vector<>, vector<>>
- priority_queue<int, int>
