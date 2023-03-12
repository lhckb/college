# Created by ddn at 08/11/2022
Feature: calculadora de números inteiros
  # Enter feature description here

  Scenario: somar dois números
    Given o primeiro operador é 3
    And o segundo operador é 2
    When eu somar os dois operadores
    Then o resultado deve ser 5

  Scenario Outline: somar dois números
    Given o primeiro operador é <operador1>
    And o segundo operador é <operador2>
    When eu somar os dois operadores
    Then o resultado deve ser <resultado>

    Examples:
    |operador1 |operador2 | resultado|
    |4         | 5        | 9        |
    |28        | 2        | 30       |