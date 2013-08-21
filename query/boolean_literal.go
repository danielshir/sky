package query

type BooleanLiteral struct {
	queryElementImpl
	value bool
}

func (l *BooleanLiteral) Codegen() (string, error) {
	return l.String(), nil
}

func (l *BooleanLiteral) String() string {
	if l.value {
		return "true"
	} else {
		return "false"
	}
}
