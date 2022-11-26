# Created by lhcc and rjhxa at 10/11/2022
Feature: calculadora de números inteiros
  # Enter feature description here

  Scenario: somar dois números
    Given o primeiro operador é 3
    And o segundo operador é 2
    When eu somar os dois operadores
    Then o resultado deve ser 5

  Scenario: subtrair dois números
    Given o primeiro operador é 9
    And o segundo operador é 8
    When eu subtrair os dois operadores
    Then o resultado deve ser 1

  Scenario: dividir dois números
    Given o primeiro operador é 36
    And o segundo operador é 6
    When eu dividir os dois operadores
    Then o resultado deve ser 6

  Scenario: multiplicar dois números
    Given o primeiro operador é 19
    And o segundo operador é 9
    When eu multiplicar os dois operadores
    Then o resultado deve ser 171

  Scenario: potenciar dois números
    Given o primeiro operador é 2
    And o segundo operador é 15
    When eu potenciar os dois operadores
    Then o resultado deve ser 32768