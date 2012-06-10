from naoqi import ALProxy
import codecs


def say_from_file(tts, filename, encoding):
    with codecs.open(filename, encoding=encoding) as fp:
        contents = fp.read()
        # warning: print contents won't work
        to_say = contents.encode("utf-8")
    tts.say(to_say)

def main():
    tts = ALProxy("ALTextToSpeech", "127.0.0.1", 9559)

    tts.setLanguage('french')
    say_from_file(tts, 'coffee_fr_utf-8.txt', 'utf-8')
    say_from_file(tts, 'coffee_fr_latin9.txt', 'latin9')

    tts.setLanguage('english')
    # the string "I like coffe" is encoded the exact same way in these three
    # encodings
    say_from_file(tts, 'coffee_en.txt', 'ascii')
    say_from_file(tts, 'coffee_en.txt', 'utf-8')
    say_from_file(tts, 'coffee_en.txt', 'latin9')

if __name__ == "__main__":
    main()

