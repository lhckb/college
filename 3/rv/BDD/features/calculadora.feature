# Created by lhcc and rjhxa at 10/11/2022
Feature: calculadora de números inteiros
  # Enter feature description here

  Scenario Outline: somar dois números
    Given o primeiro operador é <operador1>
    And o segundo operador é <operador2>
    When eu somar os dois operadores
    Then o resultado deve ser <resultado>

    Examples:
    |operador1 |operador2 | resultado|
    |4         | 5        | 9        |
    |28        | 2        | 30       |

  Scenario Outline: subtrair dois números
    Given o primeiro operador é <operador1>
    And o segundo operador é <operador2>
    When eu subtrair os dois operadores
    Then o resultado deve ser <resultado>

    Examples:
    |operador1 |operador2 | resultado|
    |10        | 8        | 2        |
    |100       | 78       | 22       |

  Scenario Outline: dividir dois números
    Given o primeiro operador é <operador1>
    And o segundo operador é <operador2>
    When eu dividir os dois operadores
    Then o resultado deve ser <resultado>

    Examples:
    |operador1 |operador2 | resultado|
    |5         | 5        | 1        |

  Scenario Outline: multiplicar dois números
    Given o primeiro operador é <operador1>
    And o segundo operador é <operador2>
    When eu multiplicar os dois operadores
    Then o resultado deve ser <resultado>

    Examples:
    |operador1 |operador2 | resultado|
    |10         | 5       | 50        |

  Scenario Outline: potenciar dois números
    Given o primeiro operador é <operador1>
    And o segundo operador é <operador2>
    When eu potenciar os dois operadores
    Then o resultado deve ser <resultado>

    Examples:
    |operador1 |operador2 | resultado|
    |2         | 15       | 32768    |