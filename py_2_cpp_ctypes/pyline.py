# code: https://github.com/jima80525/ctypes_example
# blog: https://dbader.org/blog/python-ctypes-tutorial and https://dbader.org/blog/python-ctypes-tutorial-part-2

import ctypes


class Point(ctypes.Structure):
    _fields_ = [('x', ctypes.c_int), ('y', ctypes.c_int)]

    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y

    def __repr__(self):
        return f"({self.x}, {self.y})"


class Line(ctypes.Structure):
    _fields_ = [('start', Point), ('end', Point)]

    def __init__(self, start: Point, end: Point):
        self.start = start
        self.end = end

    def __repr__(self):
        return f"Line in Python     is {self.start}->{self.end}"

    def show_line(self):
        show_line_func(self)

    def move_line(self):
        move_line_func(self)


def wrap_function(lib, funcname, restype, argtypes):
    func = lib.__getattr__(funcname)
    func.restype = restype
    func.argtypes = argtypes
    return func


libc = ctypes.CDLL("./libline.so")
get_line_func = wrap_function(libc, "get_line", Line, None)
show_line_func = wrap_function(libc, "show_line", None, [Line])
move_line_func = wrap_function(
    libc, "move_line_by_ref", None, [ctypes.POINTER(Line)])


line = Line(Point(5, 6), Point(10, 11))
print("=" * 40)
print(line)
print("=" * 40)
line.show_line()
# print(line)
# print("=" * 40)
line.move_line()
print("=" * 40)
print(line)
