function is_table_empty(table)
	if type(table) ~= 'table' then return false end
	return table == nil or next(table) == nil --t is nil or {}
end
