from sys import argv
from subprocess import run, PIPE
from os import listdir

arguments = [arg.lower() for arg in argv]
cpp_files = [fn[:-4] for fn in listdir('src') if fn[-4:] == '.c++']
c_files = [fn[:-2] for fn in listdir('src') if fn[-2:] == '.c']


def _compile(language):
    """Compile/optimize the various files in src to build."""

    def c(command, language):
        completed_process = run(
            command, shell=True, stderr=PIPE
        )
        if completed_process.returncode:
            print(f"Error compiling {language}: ", completed_process.stderr)
        completed_process.check_returncode()

    compile_command = {
        'java': "javac -d build src/*.java",
        'c': "gcc -o build/%(f)s.o src/%(f)s.c",
        'c++': "g++ -o build/%(f)s.o src/%(f)s.c++"
    }
    if language == "java" or "java" in arguments:
        c(compile_command['java'], "Java")
    if language == "c" or "c" in arguments:
        for f in c_files:
            c(compile_command['c'] % {'f': f}, "C")
    if language == "c++" or "c++" in arguments:
        for f in cpp_files:
            c(compile_command['c++'] % {'f': f}, "C++")
    else:
        for lang in "java", "c", "c++":
            _compile(lang)


def test():
    """Compile and run the tests for the specified language."""
    _compile()

    def runtest(cmd, test_type):
        completed_process = run(
            cmd,
            shell=True,
            stderr=PIPE,
            stdout=PIPE
        )
        print(
            f"         ---         {test_type} OUTPUT       ---"
            completed_process.stdout,
            sep='\n')
        if completed_process.returncode:
            print(
                f"{test_type} encountered an error:", completed_process.stderr
            )
        completed_process.check_returncode()
    if "python" in arguments:
        runtest(f"pytest {verbosity.get('pytest')} test/*.py", "PYTEST")
    if "c++" in arguments:
        runtest(
            "g++ -o test/build/test_LinkedLists test/src/test_LinkedLists.c++"
            " && test/build/test_LinkedLists",
            "CATCH"
        )


def main():
    """Interpret args."""
    verbosity = {
        'pytest': '-vv' if 'verbose' in arguments else ''
    }
    if "compile" in arguments:
        _compile()
    elif "test" in arguments:
        test()
    else:
        print("Command not recognize, please specify 'compile' or 'test'.")


if __name__ == '__main__':
    main()
