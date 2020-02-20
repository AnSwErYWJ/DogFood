--[[
	> File Name: is_table_empty.lua
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Tue 13 Mar 2018 03:00:12 PM CST
--]]

function is_table_empty(table)
	if type(table) ~= 'table' then return false end
	return table == nil or next(table) == nil --t is nil or {}
end
