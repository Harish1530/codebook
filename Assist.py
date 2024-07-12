import random
import pyttsx3
import speech_recognition as sr
import wikipedia
import datetime
import webbrowser
import pywhatkit as pk
import os
import psutil
import lyricsgenius
import spotipy
from spotipy.oauth2 import SpotifyOAuth
import difflib

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[0].id)
engine.setProperty('rate', 150)

# insert all apis here
genius = lyricsgenius.Genius("5kGwBGbNXrM1se8Bl228tnqkhDCP-0U7UX7M-Ipo9NcxDBSPn0n2fAmPacn3A5Vr")

Spotify_Client_ID = "9adbef876f6d40ae8f3e4b59c2ad211a"
Spotify_Client_Secret = "99c34a155e59480598040c532f4a6bf1"
Spotify_Redirect_Url = 'http://localhoat:8888/callback'
scope = "user-read-playback-state,user-modify-playback-state,playlist-read-private"

sp = spotipy.Spotify(auth_manager=SpotifyOAuth(client_id=Spotify_Client_ID,
                                               client_secret=Spotify_Client_Secret,
                                               redirect_uri=Spotify_Redirect_Url,
                                               scope=scope))


def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def wishme():
    hour = int(datetime.datetime.now().hour)
    if 0 <= hour < 12:
        speak("Good Morning Sir, May you have a Great Day.")
    elif 12 <= hour < 18:
        speak("Good Afternoon Sir, What can I do for you today?")
    else:
        speak("Good Evening Sir, How may I help you now?")
    speak("I am alert and Ready to complete any of your requests, Sir.")


def takecommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening...")
        r.pause_threshold = 1
        audio = r.listen(source)

    try:
        print("Recognizing...")
        query = r.recognize_google(audio, language='en-in')
        print(f"User said: {query}\n")

    except sr.UnknownValueError:
        print("Google Speech Recognition could not understand audio")
        return "None"
    except sr.RequestError as e:
        print(f"Could not request results from Google Speech Recognition service; {e}")
        return "None"
    except Exception as e:
        print(f"Please Repeat your query: {e}")
        return "None"
    return query


def check_open_browsers():
    browsers = {"chrome.exe": "Chrome", "brave.exe": "Brave"}
    open_browsers = []

    for proc in psutil.process_iter(['name']):
        if proc.info['name'] in browsers:
            open_browsers.append(browsers[proc.info['name']])

    return open_browsers


def open_browser(browser_name):
    if browser_name.lower() == 'chrome':

        chrome_path = 'C:/Program Files/Google/Chrome/Application/chrome.exe'
        webbrowser.register('chrome', None, webbrowser.BackgroundBrowser(chrome_path))
        webbrowser.get('chrome').open('https://www.google.com')
    elif browser_name.lower() == 'brave':

        brave_path = 'C:/Program Files/BraveSoftware/Brave-Browser/Application/brave.exe'
        webbrowser.register('brave', None, webbrowser.BackgroundBrowser(brave_path))
        webbrowser.get('brave').open('https://www.google.com')


def close_browser(browser_name):
    if browser_name == "chrome":
        os.system('taskkill /f /im chrome.exe')
    elif browser_name == "brave":
        os.system('taskkill /f /im brave.exe')
    else:
        speak("I can only close Chrome or Brave browsers.")


def find_song_by_lyrics(lyrics):
    try:
        song = genius.search_song(lyrics)
        return song.title + " by " + song.artist if song else None
    except Exception as e:
        print(f"An error occurred while searching for the song: {e}")
        return None


def play_song_on_spotify(songsp_name):
    resultsong = sp.search(q=songsp_name, type='track', limit=1)
    if resultsong['tracks']['items']:
        track_url = resultsong['tracks']['items'][0]['uri']
        sp.start_playback(uris=[track_url])
        speak(f"Playing {songsp_name} on Spotify")
    else:
        speak("I couldn't find the song on Spotify.")


def open_book_by_name(book_name):
    book_dir = "D:/Books to read"
    books = os.listdir(book_dir)
    closest_matches = difflib.get_close_matches(book_name, books, n=1, cutoff=0.4)

    if closest_matches:
        book_to_open = closest_matches[0]
        os.startfile(os.path.join(book_dir, book_to_open))
        speak(f"Opening {book_to_open}")
    else:
        speak("I couldn't find the book with that name.")

def listen_for_command():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print("Listening for the activation command...")
        audio = r.listen(source)

    try:
        activation_command = r.recognize_google(audio).lower()
        print(f"User said: {activation_command}")

        if 'sam' in activation_command:
            print("Activation command recognised.Listening for further commands")
            speak("Yes Sir, how may I assist you?")
            return True

    except sr.UnknownValueError:
        print("Sorry, I did not understand that.")
        # speak("Please Repeat the Command.")
    except sr.RequestError:
        print("Sorry, my speech Service is down.")
        speak("Server down. Please try again.")

    return False


if __name__ == "__main__":
    wishme()
    while True:
        if listen_for_command():
            query = takecommand().lower()

            if "introduce yourself" in query:
                wishme()
                print("My Name is Sam")
                speak("My Name is Sam")
                print("I can Do Everything that I am made capable of.")
                speak("I can Do Everything that I am made capable of.")

            elif 'what is' in query:
                speak("Searching about the query on Wikipedia...")
                query = query.replace("what is", "")
                results = wikipedia.summary(query, sentences=2)
                speak("According to Wikipedia")
                print(results)
                speak(results)

            elif 'who is' in query:
                speak("Searching about the query on Wikipedia...")
                query = query.replace("who is", "")
                results = wikipedia.summary(query, sentences=2)
                speak("According to Wikipedia")
                print(results)
                speak(results)

            elif 'just open google' in query:
                webbrowser.open('google.com')

            elif 'open google' in query:
                speak("What should I search for?")
                qry = takecommand().lower()
                webbrowser.open(f"https://www.google.com/search?q={qry}")
                results = wikipedia.summary(qry, sentences=1)
                speak(results)

            elif 'just open youtube' in query:
                webbrowser.open("youtube.com")

            elif 'open youtube' in query:
                speak("What would you like to watch today, Sir?")
                qrry = takecommand().lower()
                pk.playonyt(f"{qrry}")

            elif 'play song on spotify' in query:
                speak("What is the name of the song you wish to play?")
                qery = takecommand().lower()
                pk.playonyt(f"{qery}")
                speak("Playing it on Youtube")

            elif 'search on youtube' in query:
                query = query.replace("search on youtube", "")
                webbrowser.open(f"https://www.youtube.com/results?search_query={query}")

            elif 'open' in query and 'browser' in query:
                if 'chrome' in query:
                    open_browser('chrome')
                    speak("Chrome browser opened.")
                elif 'brave' in query:
                    open_browser('brave')
                    speak("Brave browser opened.")
                else:
                    speak("Please specify which browser to open, Chrome or Brave.")

            elif 'close' in query and 'browser' in query:
                if 'chrome' in query:
                    close_browser('chrome')
                    speak("Chrome browser closed.")
                elif 'brave' in query:
                    close_browser('brave')
                    speak("Brave browser closed.")
                else:
                    speak("Please specify which browser to close, Chrome or Brave.")

            elif 'find song by lyrics' in query:
                speak("Please say the lyrics you remember.")
                lyrics = takecommand().lower()
                if lyrics != "none":
                    song = find_song_by_lyrics(lyrics)
                    if song:
                        speak(f"I found the song: {song}. Playing it on YouTube now.")
                        pk.playonyt(song)
                    else:
                        speak("I couldn't find a song with those lyrics.")

            elif "open excel" in query:
                np = "C:/ProgramData/Microsoft/Windows/Start Menu/Programs/Excel.lnk"
                os.startfile(np)

            elif "close excel" in query:
                os.system("taskkill /f /im excel.exe")

            elif "open notepad" in query:
                np = "C:/Program Files/Notepad++/notepad++.exe"
                os.startfile(np)

            elif "close notepad" in query:
                os.system("taskkill /f /im notepad++.exe")

            elif 'play song on spotify' in query:
                speak("Please say the name of the song.")
                song_name = takecommand().lower()
                if song_name != "none":
                    play_song_on_spotify(song_name)

            elif 'open any book to read' in query:
                book_dir = "D:/Books to read"
                books = os.listdir(book_dir)
                os.startfile(os.path.join(book_dir, random.choice(books)))

            elif 'open book' in query:
                speak("Please tell the name of the book")
                book_name = takecommand().lower()
                if book_name != "none":
                    open_book_by_name(book_name)

            elif 'what time is it' in query:
                CurrTime = datetime.datetime.now().strftime("%H:%M:%S")
                speak(f"Sir, the Current time is {CurrTime}")

            elif 'lock the device' in query:
                os.system("rundll32.exe powrprof.dll,SetSuspendState 0,1,0")

            elif 'shutdown the system' in query:
                os.system("shutdown /s /t 5")