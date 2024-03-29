**Описание вычислительной машины**

- Processor	12th Gen Intel(R) Core(TM) i7-12700H   2.30 GHz
- Installed RAM	16.0 GB (15.7 GB usable)
- System type	64-bit operating system, x64-based processor
  
**Описание используемого ПО**

- Операционная система Windows 11 Home (21H2)
- OpenMP 4.5
- gcc 13.2.1 

**Оценка эффективности параллельной версии алгоритма**

Рассмотрим следующие функции:
$u_1 = x^2 + y$, $u_2 = sqrt{(x^2+y^2)}$, $u_3 = e^x + e^y$

Эксперементы будут проходить с eps = 0.01 и размером блока 64 на 1-ом и 8-ми потоках
  
<details>
<summary>Результаты эксперемента для $u_1$  </summary>

Средние значения из 10-ти запусков
![image](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/05c04408-b22f-48d2-9beb-0ef329a27e0f)

Данные по всем запуском, а также информация о доверительных интервалах представлены в таблице 
[Таблица](https://github.com/Salvatore112/Numerical-Methods-HW/blob/Task1/Task1/results/u1.xlsx)

</details>

<details>
<summary>Результаты эксперемента для $u_2$ </summary>

Средние значения из 10-ти запусков
![image](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/37799935-f82f-4e5d-afa0-def450f86bc9)

Данные по всем запуском, а также информация о доверительных интервалах представлены в таблице 
[Таблица](https://github.com/Salvatore112/Numerical-Methods-HW/blob/Task1/Task1/results/u2.xlsx)

</details>
<details>
<summary>Результаты эксперемента для $u_3$ </summary>

Средние значения из 10-ти запусков
![image](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/505bbb29-5878-4e1c-a31f-5229936c8475)

Данные по всем запуском, а также информация о доверительных интервалах представлены в таблице 
[Таблица](https://github.com/Salvatore112/Numerical-Methods-HW/blob/Task1/Task1/results/u3.xlsx)

</details>

Исходя из данных результатов, можно заметить, что на меньших размерах сетки ускорения не происходит из-за того что размеры блока очень большие по сравнению с размерами сетки, что не позволяет эффективно распараллелить вычисления между потоками, например, на сетке размера 100 будет всего один блок (почти полностью покрывающий сетку), что решительно не позволяет использовать приемущества параллельной среды (что ожидалось наблюдать после прочтения книги и анализа полученныех в ней результатов). Кроме того, общие причины, которые могут повлиять на ускорение распараллеливания для всех этих трех функций могут быть следующие:
- Эти функции включают относительно простые математические операции, которые могут не полностью использовать вычислительные ресурсы, доступные в средах параллельного выполнения
- Все три функции имеют зависимости данных или последовательные вычисления, которые ограничивают возможный уровень параллелизма. Например, в $sqrt(x^2+y^2)$ каждое вычисление зависит от результата операции извлечения квадратного корня, что ограничивает параллельное выполнение

Давайте теперь рассмотрим следующую функцию:
$u_4$ = sin(100*x) * cos(100*y)

<details>
<summary>Результаты эксперемента для $u_4$ с теми же условиями </summary>

Средние значения из 10-ти запусков
![image](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/e7e740ed-983c-4bf5-815b-ecd506033d40)


Данные по всем запуском, а также информация о доверительных интервалах представлены в таблице 
[Таблица](https://github.com/Salvatore112/Numerical-Methods-HW/blob/Task1/Task1/results/u4.xlsx)

</details>

Можно наблюдать то, что ускорение в данном случае намного выше, что может быть связано с самой функцией $u_4$, содержащей синус и косинус, вычисление значений которых может потребовать множество арифметических операций, что может быть эффективно распаралелено.

