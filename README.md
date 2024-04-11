# Домашние задания и контрольные по предмету "Математика в информационных технологиях". 4-ый семестр.

# Задача 1

Давайте рассмотрим книгу В. П. Гергеля “Высокопроизводительные вычисления для
многоядерных многопроцессорных систем” (2010). В главе 11 "Решение
дифференциальных уравнений в частных производных", описывающей проблему
численного решения задачи Дирихле для уравнения Пуассона, содержится алгоритм
11.6 (Блочный подход к методу волновой обработки данных) её решения, который
может быть эффективно распараллелен при помощи OpenMP.

В первой части задания вам следует просто разобраться в этом алгоритме и
реализовать его. Обратите внимание, что он возникает итерационно. Например,
алгоритм 11.2 является корректным, но распараллеливание приводит к замедлению в
25 раз вместо ускорения.

Вторая часть задания — провести численный эксперимент, исследующий
эффективность (или неэффективность) параллельной версии. Модельные краевые
задачи необходимо выбрать самостоятельно, исходя из того, что вы хотели бы теми
или иными экспериментами продемонстрировать. Это наиболее сложная часть
задания.

[Решение](https://github.com/Salvatore112/Numerical-Methods-HW/tree/Task1/Task1)

# Задача 2. Maple и методы аппроксимации сплайнами
Напишите скрипт на языке Maple, который позволяет для данной функции f построить
её интерполяцию на основе кубических сплайнов, а также квадратичных B-сплайнов на
равномерной сетке на отрезке [0; 1] c шагом 0,1. Подберите набор тестовых функций,
демонстрирующих преимущества и недостатки используемых сплайнов.
Алгоритмы построения сплайн-функций необходимо написать самостоятельно (при
этом, разумеется, разрешается использовать стандартные средства для решения
СЛАУ, например), а после проверить их корректность при помощи соответствующих
стандартных средств построения сплайнов в Maple.

Комментарии:
1) Вопросы преимуществ и недостатков рассматриваемых сплайн-функций уже изучались
ранее, поэтому лучше взять некий авторитетный источник и показать на примере
корректность описанной информации. Например, сказать, что “в статье X утверждается,
что B-сплайны плохо приближают конические сечения”. И показать это на примере
некого конического сечения. Подобные комментарии необходимо оставить
непосредственно в коде скрипта.

2) Качество построенного приближения необходимо вычислять как максимальное
абсолютное значение отклонения реального значения тестируемой функции от
приближённого. Сравнение проводить на равномерной сетке, в десять раз более
мелкой, чем исходная.

3) В качестве коэффициентов при B-сплайнах необходимо рассмотреть значения
аппроксимационных функционалов из конца раздела 8.2.2 (A three-point quadratic
quasi-interpolant) книги T. Lyche & K. Morken “Spline methods”. При этом желательно
разобраться в методе их построения.

[Решение](https://github.com/Salvatore112/Numerical-Methods-HW/tree/Task2/Task2)

# Задача 3

## Часть I
Реализуйте программу на языке Python, которая производит сжатие изображения в формате bmp (24
бита на цвет) с минимизацией потери качества при фиксированном ограничении на размер сжатого
файла, используя теорию малоранговых приближений. Ваша программа должна семантически
распадаться на две единицы логики: формирование промежуточного представления на основе
исходного изображения, а также восстановление, использующее промежуточное представление.
Для хранения промежуточного сжатого представления используйте собственный формат файла; его
размер (включая область метаданных) должен быть в хотя бы в N раз меньше исходного, где N –
настраиваемый параметр. Напишите краткую документацию предложенного вами формата и
приложите её к решению задачи.
Сингулярное разложение реализуйте тремя способами:
- пользуясь стандартными библиотеками
- с помощью самописного примитивного алгоритма
- “максимально хорошим” численным методом, который у вас получится написать
Обратите внимание, что даже в рамках стандартных библиотек Python есть две реализации SVD.
Можно попробовать обратиться к исходному коду, описаниям реализации и исходя из этого
подумать о частных случаях, позволяющих улучшать качество.
Роль примитивного алгоритма могут выполнять, например, степенной метод или какой-то из
описанных в пособии Дж Голуб, Ч. ван Лоун "Матричные вычисления." – Москва: Мир, 1999.
Приведу также пару статей, в которых излагаются современные подходы к решению задачи, но это
вовсе не значит, что вам нужно и даже стоит использовать именно их.
- https://core.ac.uk/download/pdf/82260137.pdf
- https://www.degruyter.com/document/doi/10.1515/jisys-2018-0034/html
 
## Часть II
Подберите достаточно большое изображение, на котором будет (насколько это возможно видна)
разница в сохранности или потере ключевых признаков при его сжатии в одинаковое количество
раз при использовании различных реализаций SVD.
Возможно, эта задача не решится путём подбора изображения. Тогда следует отталкиваться от того,
какие матрицы каким алгоритмом лучше обрабатывать. То есть рассматривать матрицу как
первичный объект, а построенное на его основе изображение — как вторичный. Ещё можно
наложить дополнительные ограничения: например, предоставить различным алгоритмам
одинаковое время работы.
[Решение](https://github.com/Salvatore112/Numerical-Methods-HW/tree/Task3/Task3)
