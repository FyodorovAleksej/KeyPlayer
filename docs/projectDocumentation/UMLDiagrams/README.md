## UMLDiagarms:

 1. [Диаграммы активности](#Activity)
 2. [Диаграмма классов](#Class)
 3. [Диаграмма последовательности](#Sequence)
 4. [Диаграмма состояний](#State) 
 5. [Диаграмма развёртывания](#Deploy) 
 6. [Диаграмма прецедентов](#UseCase)


<a name="Activity"></a>
### 1. Диагаммы активности
Диагаммы активности более подробно расписаны в следующем документе: [*Диаграммы активности*](https://fyodorovaleksej.github.io/KeyPlayer/projectDocumentation/UMLDiagrams/Activity/Activity)
<a name="Class"></a>
### 2. Диаграмма классов
Диаграмма классов представляет собой следующую диаграмму:
![Диаграмма классов](https://fyodorovaleksej.github.io/KeyPlayer/projectDocumentation/UMLDiagrams/Class/ClassDiagram.jpg)
На диаграмме указаны некоторые стереотипы:

 - \<\<create\>\> - Конструктор. Метод который будет вызываться при создании объекта класса
 - \<\<destroy\>\> - Деструктор. Метод, который будет вызываться при уничтожении объекта
 - \<\<slot\>\> - Слот. Метод который будет вызваться при срабатывании определённого условия, с которым он связан в любой момент времени
 - \<\<signal\>\> - Сигнал. Сигнал, который будет передаваться к связанным с ним слотам

<a name="Sequence"></a>
### 3. Диаграмма последовательности
Диаграмма последовательности основного варианта использования представляет из себя следующую диаграмму:
![Диаграмма последовательности](https://fyodorovaleksej.github.io/KeyPlayer/projectDocumentation/UMLDiagrams/Sequence/SequenceDiagram.jpg)

<a name="State"></a>
### 4. Диаграмма состояний
На диаграмме состояний показаны состояния объекта класса KeyButton при взаимодействии его с Окном проигрывания и соответствующим Ключом. Диаграмма представлена ниже
![Диаграмма состояний](https://fyodorovaleksej.github.io/KeyPlayer/projectDocumentation/UMLDiagrams/State/KeyStateDiagram.jpg)

<a name="Deploy"></a>
### 5. Диаграмма развёртывания
Диаграмма развёртывания представляет собой следующую диаграмму:
![Диаграмма развёртывания](https://fyodorovaleksej.github.io/KeyPlayer/projectDocumentation/UMLDiagrams/Deploy/DeploymentDiagramm.jpg)

<a name="UseCase"></a>
### 6. Диаграмма прецедентов
Диаграмма прецедентов представляет собой следующую диаграмму:
![Диаграмма прецедентов](https://fyodorovaleksej.github.io/KeyPlayer/projectDocumentation/UMLDiagrams/UseCase/UseCaseDiagram.jpg)
