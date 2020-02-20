--[[
	> File Name: test_is_table_empty.lua
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Tue 13 Mar 2018 03:01:42 PM CST
--]]

package.path = package.path .. ';' .. '../?.lua;'
require 'is_table_empty'

local t1 = {}
local t2 = {
    a = 1
}
local t3 = 888
local t4 = 'abc'

print("nil is empty table ?", is_table_empty(nil))
print("table {} is empty table ?", is_table_empty(t1))
print("table {a = 1} is empty table ?", is_table_empty(t2))
print("number 888 is empty table ?", is_table_empty(t3))
print("string abc is empty table ?", is_table_empty(t4))
