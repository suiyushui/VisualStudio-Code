from abc import abstractmethod
class animal:
    @abstractmethod
    def speek(self):
        pass

class dog(animal):
    def speek(self):
        print("Woof!")

class cat(animal):

    def speek(self):
        print("Meow!")
def speek(animal):
    animal.speek()
dog1=dog()
cat1=cat()
speek(dog1)
speek(cat1)

