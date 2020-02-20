--[[
	> File Name: test_module.lua
	> Author: weijie.yuan
	> Mail: yuanweijie1993@gmail.com
	> Created Time: Tue 13 Mar 2018 03:29:09 PM CST
--]]

package.path = package.path .. ';' .. '../?.lua;'

local m = require 'module'

local account = m.new(100, {name = 'answer', age = 'xxx'})

if not account then
	print("your account is error")
	m = nil
	return
end

m = nil

print("your balance is ", account.balance)
print("your bank is ", account.info.bank)
account:deposit(200)
print("after deposit 200, your balance is ", account.balance)
account:withdraw(100)
print("after withdraw 100, your balance is ", account.balance)