interface IAnimal {
  walk(): void;
  eat(): void;
  sleep(): void;
}

class Dog implements IAnimal {

  walk(): void {
    console.log('on four legs...')
  }

  eat(): void {
    console.log('meat...')
  }

  sleep(): void {
    console.log('all day long...')
  }
}
