## HomeWork 4
- Сгенерируйте слачайные графы и протестируйте пересчет числа маршрутов в графе через вычисление степени матрицы связности __A^m__. Реализуйте через быстрое возвежение в степень за __log_2(m)__ матричных умножений (30 %).

__закоментировать все что связано с <omp.h>__
```bash
g++ routes.cpp matrix.cpp -o routes && ./routes
```

- Сгенерируйте (или предложите) небольшой случайный граф и реализуйте процедуру вычисления вектора Pagerank. Сопоставьте с наивным ранжированием по числу входящих ссылок ranking (40 %).

__закоментировать все что связано с <omp.h>__
```bash
g++ page_rank.cpp matrix.cpp -o page_rank && ./page_rank
```

- Воспользуйтесь всеми трюками по оптимизации производительности: optimization, blas, openmp, loops placing (30 %)
```bash
g++-6 -fopenmp routes.cpp matrix.cpp -o routes && ./routes
g++-6 -fopenmp page_rank.cpp matrix.cpp -o page_rank && ./page_rank
```