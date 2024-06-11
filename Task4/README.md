**Описание вычислительной машины**

- Processor	12th Gen Intel(R) Core(TM) i7-12700H   2.30 GHz
- Installed RAM	16.0 GB (15.7 GB usable)
- System type	64-bit operating system, x64-based processor

**Условя**

Дифференциальное уравнение: $y'' - λy = -2λ * sin(\sqrt{λ}*x)$ с решением $y = sin(sqrt(λ)*x)$ и граничными
условиями $y(0) = 0$ $y(4 * pi/\sqrt{λ})$

**Численный экспиремент**

<details>
<summary>Результаты</summary>

Результаты эксперемента для λ = 1 <br>
![1](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/419dd6e9-a989-4e41-8aa4-d9f6a25c674d)
 <br>
Результаты эксперемента для λ = 10 <br>
![10](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/0f9c1a8e-68cd-4714-9e9f-49726897d512)
 <br>
Результаты эксперемента для λ = 20 <br>
![20](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/cc2d070b-575f-4bdb-8aac-d684545ba348)
 <br>
Результаты эксперемента для λ = 30 <br>
![30](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/7c74e18c-e37b-4d23-8e39-93301aa04452)
 <br>
Результаты эксперемента для λ = 40 <br>
![40](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/4fb469cc-563f-4ac6-b6f9-7413ca303a8b)
 <br>
Результаты эксперемента для λ = 50 <br>
![50](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/f52203fe-3fd5-466a-85fc-9f7585d804ec)
 <br>
Результаты эксперемента для λ = 60 <br>
![60](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/c9fecfc1-5066-4e73-a670-357a383d65d5)
 <br>
Результаты эксперемента для λ = 70 <br>
![70](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/852ed203-c36b-4716-9bde-01124e1cced3)
 <br>
Результаты эксперемента для λ = 75 <br>
![75](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/c58b1ca5-f7fb-4401-8006-0d4b829eb8aa)
 <br>
Результаты эксперемента для λ = 80 <br>
![80](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/8acb2550-a375-47f7-a3a9-151a5dd83335)
 <br>
Результаты эксперемента для λ = 85 <br>
![85](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/cfba7082-9a7d-4cf0-98bd-bd1b09b74fe5)
 <br>
Результаты эксперемента для λ = 90 <br>
![90](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/86c7f039-8e24-44b3-ae51-2c7fffab7d09)
 <br>
Результаты эксперемента для λ = 95 <br>
![95](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/cd2dd828-c2bb-417a-96e2-c9c43805a4ef)
 <br>
Результаты эксперемента для λ = 100 <br>
![100](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/a391594c-0293-43b1-bce7-122c8e0c8286)
 <br>
Результаты эксперемента для λ = 150 <br>
![150](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/b34023a0-2a4b-4df5-a367-456a6b541942)
 <br>
Результаты эксперемента для λ = 200 <br>
![200](https://github.com/Salvatore112/Numerical-Methods-HW/assets/113641510/64878a8f-1d98-4fdf-a656-e9c68e9c12d3)


</details>

Итого, видно, что на достаточно малых λ теоретическая оценка $(4 * pi/\sqrt{λ} * n)^2$ где n - размер сетки выполняется, однака начиная с λ = 75, оценка перестает достигаться на малых размерах сетки. С ростом λ оценка перестает достигаться все на больших размерах сетки (что можно проследить на графиках с λ = 75 до λ = 200)
