class Vader:

  # classe pai e seu método
  def fatherMessage():
    print('luke...')

class Padme:

  # outra classe pai e seu método
  def motherMessage():
    print('lol your dad went full sith mode then i died')

class Luke(Vader, Padme):

  # classe child herdando duas classes pais
  pass

Luke.fatherMessage()
Luke.motherMessage()


class Skater:

  # Skater tem um método greeting
  def greeting():
    print('i skate')

class Surfer:

  # Surfer também tem um método greeting
  def greeting():
    print('i surf')

class AverageCalifornian(Skater, Surfer):

  pass

# qual será o output dessa chamada?
AverageCalifornian.greeting()