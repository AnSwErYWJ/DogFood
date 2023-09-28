local _M = {}

_M._VERSION = '1.0'

local mt = {__index = _M }

--[[
    1.avoid naming conflict 
    2.local is faster then global
--]]
local print = print 

function _M.deposit(self, v)
    self.balance = self.balance + v
end

function _M.withdraw(self, v)
    if self.balance > v then
        self.balance = self.balance - v
    else
        print("insufficient funds")
    end
end

function _M.new(balance, info)
    if (balance and type(balance) ~= 'number') or (info and type(info) ~= 'table') then return false end

    balance = balance or 0
    info.bank = 'ohmygood'

    return setmetatable({balance = balance, info = info}, mt) -- protect private attribute
end

return _M

